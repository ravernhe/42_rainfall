undefined4 main(int ac,char **av)

{
  undefined4 uVar1;
  int i;
  undefined4 *puVar2;
  byte bVar3;
  undefined4 local_98 [16];
  undefined local_57;
  char local_56 [66];
  FILE *fd;
  
  bVar3 = 0;

# open .pass
  fd = fopen("/home/user/end/.pass","r");
  puVar2 = local_98;
# bzero
  for (i = 33; i != 0; i = i + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
  }
# if no file and ac != 2 c non
  if ((fd == (FILE *)0x0) || (ac != 2)) {
    uVar1 = 0xffffffff;
  }
  else {
    fread(local_98,1,66,fd);
    local_57 = 0;
# atoi notre arg et met un '\0' a la postion buff[i]
    i = atoi(av[1]);
    *(undefined *)((int)local_98 + i) = 0;
    fread(local_56,1,0x41,fd);
    fclose(fd);
# strcmp compare jusqu'a un '\0'
    i = strcmp((char *)local_98,av[1]);
    if (i == 0) {
      execl("/bin/sh","sh",0);
    }
    else {
      puts(local_56);
    }
    uVar1 = 0;
  }
  return uVar1;
}
