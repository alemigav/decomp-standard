/* FUN_80166978
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166978  body 0x80166978..0x80166a03  size 140 B
 * body sha256 a6dda793a22d84d633eaab371bbc889cf1de9d01007ba128192fe9d6590cd098
 * provider record sha256 6728ad85a9fe1d9217946052cb194f14e5f090881f8f50701a842bc66cf02fc1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166978(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x2b8) != '\0') {
    iVar2 = *(int *)(param_1 + 0x234);
    sVar1 = *(short *)(param_1 + 0x2ba);
    *(short *)(iVar2 + 0x1084) = -sVar1;
    func_0x80040e58(iVar2 + 0x1080,iVar2 + 0x1030);
    *(short *)(iVar2 + 0x11fa) = sVar1;
    *(short *)(iVar2 + 0x11fc) = sVar1 << 1;
    func_0x80040e58(iVar2 + 0x11f8,iVar2 + 0x11a8);
    *(short *)(iVar2 + 0x1372) = -sVar1;
    *(short *)(iVar2 + 0x1374) = sVar1 << 1;
    func_0x80040e58(iVar2 + 0x1370,iVar2 + 0x1320);
  }
  return;
}
