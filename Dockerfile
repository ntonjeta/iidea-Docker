FROM mariobarbareschi/clang_llvm391

MAINTAINER Giovanni Panice <n@mosfet.io>
MAINTAINER Antonio Tammaro <ntonjeta@autistici.org>

#RUN rm /bin/sh && ln -s /bin/bash /bin/sh

# Update Software 
# Default command at startup
RUN pacman --noconfirm -Syu

# Install essential packages
run pacman --noconfirm -S git zsh libedit libffi wget libtar doxygen 


# Copy install script
ADD . /opt/install-iidea

SHELL ["/bin/bash", "-c"]

# Run script Install 
RUN /opt/install-iidea/install-chimera
RUN /opt/install-iidea/install-paradiseo
RUN /opt/install-iidea/install-bellerophon

# Create a new user
RUN useradd -ms /bin/bash homer

# Expose user
#USER homer

