FROM mariobarbareschi/clang_llvm391

MAINTAINER Giovanni Panice <n@mosfet.io>
MAINTAINER Antonio Tammaro <ntonjeta@autistici.org>

# Update Software 

# Default command at startup
RUN pacman --noconfirm -Syu

# Install essential packages
run pacman --noconfirm -S git zsh libedit libffi wget libtar doxygen

CMD bash

# Copy install script
ADD . /opt/install-iidea

# Run script Install 
RUN /opt/install-iidea/install-paradiseo
#RUN /opt/install-iidea/install-bellerophon
#RUN /opt/install-iidea/install-iidea

# Create a new user
RUN useradd -ms /bin/bash homer

# Expose user
#USER homer

