# KaliForge

<p align="center">
 <img height=400px weight=400px src=".assets/KaliForge.png" >
</p>

## Introduction

KaliForge is a powerful automation project designed to streamline the customization and provisioning process of a fresh Kali Linux installation.This project utilizes Ansible playbooks, allowing users to effortlessly install and configure a comprehensive set of tools tailored for pentest and red team operations.

Installing and setting up Kali Linux with all the necessary tools traditionally involves numerous manual steps, which can be time-consuming and prone to errors. KaliForge aims to simplify this process by automating the installation of essential tools and configurations, providing users with a consistent and reliable environment from the start.

## Instructions

On your fresh KaliLinux installation, install ansible
```bash
sudo apt update
sudo apt install ansible-core
```  

Clone repo and install dependencies
```bash
git clone https://github.com/v4resk/KaliForge
cd KaliForge
ansible-galaxy install -r requirements.yml
```

Run it
```bash
ansible-playbook main.yml -K
```

## References
KaliForge was largely inspired by IppSec's [parrot-build](https://github.com/IppSec/parrot-build) project.
