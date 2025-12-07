# statfs-test

Little tester for the statfs() system call.

See `man statfs`.


## Build Requirements

- C++ compiler
- make


## Building

```
make statfs-test
```

No Makefile needed.


## Usage

```
statfs /some/path
```


## Sample Usage

```console
# df -h /usr
Filesystem      Size  Used Avail Use% Mounted on
/dev/nvme0n1p3   98G   14G   83G  14% /

# ./statfs-test /usr
statfs() for /usr:
  filesystem type:  0xef53
  total blocks:     25656558
  free  blocks:     22163569
  available blocks: 21635185
  fragment size:    4096

# ./statfs-test /usr/share
statfs() for /usr/share:
  filesystem type:  0xef53
  total blocks:     25656558
  free  blocks:     22163569
  available blocks: 21635185
  fragment size:    4096

# ./statfs-test /usr/lib
statfs() for /usr/lib:
  filesystem type:  0xef53
  total blocks:     25656558
  free  blocks:     22163569
  available blocks: 21635185
  fragment size:    4096

# ./statfs-test /usr/bin
statfs() for /usr/bin:
  filesystem type:  0xef53
  total blocks:     25656558
  free  blocks:     22163569
  available blocks: 21635185
  fragment size:    4096

# 
```

I.e. no matter what path you use, as long as it's on the same filesystem,
statfs() always returns the same values: Those for the entire filesystem, not
for any specific subtree.


## License

GPL V2