#!/usr/bin/env bash
# Script for flashing via dfuutil via wsl
# Works around the QMK toolbox limitation of not polling often enough,
# making Caterina devices go to the keyboard mode too early.
set -eou pipefail

where_bin="/mnt/c/Windows/System32/where.exe"
if [[ ! -x "$where_bin" ]]; then
  echo "where.exe not found. Ensure you're running WSL."
  exit 1
fi

dfuutil_windows_bin=$("$where_bin" dfu-util.exe || true)
if [[ -z "$dfuutil_windows_bin" ]]; then
  echo "dfu-util.exe not found. Try 'scoop install dfu-util'"
  exit 1
fi

dfuutil_bin2="$(echo "$dfuutil_windows_bin" | tr '\\' '/' | tr -d '\r' | tr -d ':')"
dfuutil_bin="/mnt/${dfuutil_bin2,}" # downcase first char

firmware="planck_rev6_rsta.bin"

while true; do
  # https://github.com/qmk/qmk_firmware/blob/master/docs/flashing.md#stm32apm32-dfu
  if "$dfuutil_bin" -a -d 0483:DF11 -s 0x8000000:leave -D "$firmware"; then
    break 1
  fi
  sleep 0.01
done
