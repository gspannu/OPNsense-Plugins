## Install this plugin on OPNsense

---

1. Login to OPNsense shell.
2. Execute the below two commands in OPNsense shell (either as root user or use sudo)

```
sudo fetch -o /usr/local/etc/pkg/repos/os-blocky-plugin.conf https://raw.githubusercontent.com/gspannu/OPNsense-Plugins/main/repo-config/os-blocky-plugin.conf;
sudo pkg update
```

2. On OPNsense, login to GUI. Go to System> Firmware> Plugins and search for os-blocky
3. Install os-blocky
4. Refresh the browser page to reload OPNsense GUI

5. If Blocky is being used as the 'Primary DNS' then remember to _**disable**_ Unbound/dnsmasq or setUnbound/dnsmasq _**listening port**_ to something other than _**53**_, else Blocky DNS will not execute and throw an error.
6. Goto Services, and a new entry for Blocky DNS should be available. Enable/ use as appropriate.
7. Once Blocky is confirmed working, you may configure the Blocky DNS configuration by directly editing blocky-config.yml file in /usr/local/etc/blocky-config.yml. Use something like `nano /usr/local/etc/blocky-config.yml`.
8. On OPNsense GUI > Disable and Renable Blocky DNS
9. All errors are logged in '/var/log/blocky.log'
10. Also check that Blocky DNS is working as the **primary dns** resolver.
In OPNsense shell, execute `cat /etc/resol.conf` and it should have a nameserver entry for localhost (e.g. _nameserver 127.0.0.1_).
```
[OPNsense] router:~ $ cat /etc/resolv.conf 
domain home
nameserver 127.0.0.1
search home
```
>OPNsense may require a restart for this to work. It is advisable to restart OPNsense and check this.

   ---
   
### Happy Ad-blocking
