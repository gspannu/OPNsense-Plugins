## Install on OPNsense

1. execute the below 2 commands in OPNsense shell (as root user or sudo)

```
fetch -o /usr/local/etc/pkg/repos/os-blocky-plugin.conf https://raw.githubusercontent.com/gspannu/OPNsense-Plugins/main/repo-config/os-blocky-plugin.conf;
pkg update
```

2. On OPNsene, login to GUI. Go to System>Firware>Plugins and search for os-blocky
3. Install os-blocky
4. Refresh the browser page to reload OPNsense GUI

5. If Blocky is being used as the 'Primary DNS' then remember to _disable_ Unbound/dnsmasq or setUnbound/dnsmasq _listening port to something other than 53_, else Blocky DNS will not execute and throw an error.
6. Goto Services, and a new entry for Blocky DNS should be available. Enable/ use as appropriate.
7. Once Blocky is confirmed working, you may configure the Blocky DNS configuration by directly editing blocky-config.yml file in /usr/etc/config-blocky.yml. Use something like `nano /usr/local/etc/blocky-config.yml`.
8. Disable and Renable Blocky DNS
9. Errors are logged in '/var/log/blocky.log'
10. Also check that Blocky DNS is working as th eprimary dns resolver. In OPNsense shell, check `cat /etc/resol.conf` and it should have a nameserver entry for localhost (e.g. nameserver 127.0.0.1). OPNsense may require a restart for this. It is always advisable to restart OPNsense and check for this as well.
```
[OPNsense] router:~ $ cat /etc/resolv.conf 
domain home
nameserver 127.0.0.1
search home
```
   ---
   
### Happy Ad-blocking
