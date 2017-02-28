FROM base/archlinux
MAINTAINER Giovanni Panice <n@mosfet.io>
MAINTAINER Antonio Tammaro <ntonjeta@autistici.org>

# Update Software 

# Default command at startup
RUN pacman -Syu

# Install essential packages
run pacman --noconfirm -S git vim cmake zsh 

CMD bash

# Copy install script
ADD . /opt/install-clang

# Run script Install clang
RUN /opt/install-clang/install-clang

# Create a new user
RUN useradd -ms /bin/bash homer

# Expose user
USER homer

