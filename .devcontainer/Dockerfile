# Base image
FROM mcr.microsoft.com/devcontainers/base:ubuntu-22.04

# Install basic C development tools and dependencies
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        build-essential \
        gdb \
        valgrind \
        cmake \
        git \
        curl \
        unzip \
        zsh \
        vim && \
		apt-get clean && rm -rf /var/lib/apt/lists/*

RUN curl -fsLS get.chezmoi.io | sh


# Optional: Install mise from official mise image (if you use it)
COPY --from=jdxcode/mise /usr/local/bin/mise /usr/local/bin/

# Enable mise in both bash and zsh shells for user vscode
RUN echo 'eval "$(mise activate bash)"' >> /home/vscode/.bashrc && \
    echo 'eval "$(mise activate zsh)"' >> /home/vscode/.zshrc

# Set default git config (optional, in case dotfiles don't cover it)
RUN git config --global user.name "japostad" && \
    git config --global user.email "japostad@student.42barcelona.com"

# Set default shell to zsh (optional)
SHELL ["/bin/zsh", "-c"]

# Set working directory (must match devcontainer.json workspaceFolder if set)
WORKDIR /workspaces/project
