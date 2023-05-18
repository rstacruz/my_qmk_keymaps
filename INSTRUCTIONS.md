# Instructions

```bash
cd qmk-crkbd-promicro
make docker        # Build using Docker
make docker-flash  # Flash using Docker
```

## Using containerd and nerdctl

[nerdctl](https://github.com/containerd/nerdctl) is a drop-in replacement for Docker powered by [containerd](https://containerd.io/). Assuming containerd and nerdctl are all set up (also see [common instructions](https://rootlesscontaine.rs/getting-started/common/)), try:

```bash
RUNTIME=nerdctl make docker
```

