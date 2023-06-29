# KaliForge

<p align="center">
 <img height=400px weight=400px src=".assets/KaliForge.png" >
</p>

## Instructions

Install ansible
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
ansible-playbook main.yml
```

## References
KaliForge was largely inspired by IppSec's [parrot-build](https://github.com/IppSec/parrot-build) project.
