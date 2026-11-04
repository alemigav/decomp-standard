/* FUN_80166ae8
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166ae8  body 0x80166ae8..0x80166bef  size 264 B
 * body sha256 293061399adb0552cf46816829bb87f89fe5341c4e4e2713596c4efad3ea1957
 * provider record sha256 6590c56ff9e6ce1496c938237a85250a37b8a8318d322b8a070db060521a2af2
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166ae8(uint *param_1)

{
  char cVar2;
  int iVar1;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    DAT_80167540 = 0;
    func_0x80077d18(8,param_1);
    FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,0);
    *param_1 = *param_1 | 2;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 1:
    cVar2 = func_0x80036d14(param_1,0x14,0,0);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    if (-1000 < *(short *)((int)param_1 + 0x2d6)) {
      *(short *)((int)param_1 + 0x2d6) = *(short *)((int)param_1 + 0x2d6) + -0x32;
    }
    break;
  case 2:
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 3:
    iVar1 = func_0x80036be4(param_1,0xb,0xf,0);
    if (iVar1 != 0) {
      *(undefined1 *)((int)param_1 + 0x2b7) = 1;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
  }
  return;
}
