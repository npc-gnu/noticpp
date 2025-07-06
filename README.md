# noticpp
- **NotiCPP** is a software to make you remind something.

> Note: THIS SOFTWARE ONLY WORKS ON BASH AND ZSH! 
## How it works?
It adds your input to *~/.bashrc* or *~/.zshrc* and every opening of your terminal it says your input.

## How to install?

### 1. Install dependency's
#### Arch based:
```bash
sudo pacman -S git gcc
```
#### Debian/Ubuntu based:
```bash
sudo apt install git g++
```
#### Fedora based:
```bash
sudo dnf install git gcc-c++
```
#### openSUSE based:
```bash
sudo zypper install git gcc-c++
```

### 2. Do everything else with a single command
```bash
git clone https://github.com/npc-gnu/noticpp && cd noticpp && g++ -o install install.cpp && ./install
```

## Usage:
Now you can add reminders to your terminal with `noticpp` .

## LICENSE

This software and every part of it licensed by GNU is Not Unix Affero General Public License version 3(AGPLv3).
