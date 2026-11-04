/* FUN_801626c4
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801626c4  body 0x801626c4..0x8016286f  size 428 B
 * body sha256 622a378644e931c2d62f507d75591ad8cb9e8b0e7aa936736172b965916bac07
 * provider record sha256 4cb34652984ead7cc701f44994d6aeaf7b8251ce8e3eefc075d12a55eb745788
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801626c4(int param_1)

{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 0x2ba)) {
  case 0:
    DAT_80166650 = 0;
    *(char *)(param_1 + 0x2ba) = *(char *)(param_1 + 0x2ba) + '\x01';
  case 1:
    iVar1 = *(int *)(iVar1 + 0x878);
    sVar2 = (short)((uint)(DAT_80166650 * DAT_80166650 * 0x800) / 100);
    break;
  case 2:
    DAT_80166650 = DAT_80166650 + -1;
    if (DAT_80166650 == 0) {
      *(char *)(param_1 + 0x2ba) = *(char *)(param_1 + 0x2ba) + '\x01';
    }
    iVar1 = *(int *)(iVar1 + 0x878);
    sVar2 = 0x1000 - (short)((uint)(DAT_80166650 * DAT_80166650 * 0x800) / 100);
    goto LAB_80162854;
  case 3:
    iVar1 = *(int *)(iVar1 + 0x878);
    sVar2 = 0x1000 - (short)((uint)(DAT_80166650 * DAT_80166650 * 0x800) / 100);
    break;
  case 4:
    DAT_80166650 = DAT_80166650 + -1;
    if (DAT_80166650 == 0) {
      *(undefined1 *)(param_1 + 0x2ba) = 1;
    }
    iVar1 = *(int *)(iVar1 + 0x878);
    sVar2 = (short)((uint)(DAT_80166650 * DAT_80166650 * 0x800) / 100);
LAB_80162854:
    *(short *)(iVar1 + 0xc) = sVar2;
    func_0x80066288(param_1);
  default:
    goto switchD_80162700_default;
  }
  *(short *)(iVar1 + 0xc) = sVar2;
  func_0x80066288(param_1);
  DAT_80166650 = DAT_80166650 + 1;
  if (DAT_80166650 == 10) {
    *(char *)(param_1 + 0x2ba) = *(char *)(param_1 + 0x2ba) + '\x01';
  }
switchD_80162700_default:
  return;
}
