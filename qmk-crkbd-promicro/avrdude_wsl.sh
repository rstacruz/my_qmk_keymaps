#!/usr/bin/env bash
# Script for flashing via avrdude via wsl
# Works around the QMK toolbox limitation of not polling often enough,
# making Caterina devices go to the keyboard mode too early.
set -eou pipefail

where_bin="/mnt/c/Windows/System32/where.exe"
if [[ ! -x "$where_bin" ]]; then
  echo "where.exe not found. Ensure you're running WSL."
  exit 1
fi

avrdude_windows_bin=$("$where_bin" avrdude.exe)
if [[ -z "$avrdude_windows_bin" ]]; then
  echo "avrdude.exe not found. Try 'scoop install avrdude'"
  exit 1
fi

avrdude_bin2="$(echo "$avrdude_windows_bin" | tr '\\' '/' | tr -d '\r' | tr -d ':')"
avrdude_bin="/mnt/${avrdude_bin2,}" # downcase first char

firmware="crkbd_rev1_rsta2.hex"

# echo "Press enter, then put the keyboard in bootloader mode."
# read

while true; do
  for port in COM{1..8}; do
    if "$avrdude_bin" -p ATmega32U4 -c avr109 -P "$port" -U flash:w:"$firmware":i; then
      break 2
    fi
  done
  # sleep 0.01
done
