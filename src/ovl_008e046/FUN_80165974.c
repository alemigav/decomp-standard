/* FUN_80165974
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80165974  body 0x80165974..0x80165a83  size 272 B
 * body sha256 2fd14a3a834501397ddf6dbe6309207d76042a9c5a440b330d2092bac4e3c807
 * provider record sha256 f8408f5a1a356ea5a7001bab561ea3d0722b048ab2fdd32d3f1678198ea07022
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165974(int param_1)

{
  char cVar2;
  ushort uVar1;
  
  if ((*(ushort *)(param_1 + 0x2c8) & 0x40) != 0) {
    *(undefined1 *)(param_1 + 0x26e) = 0;
    return;
  }
  if ((*(int *)(param_1 + 700) != 0) ||
     (*(int *)(param_1 + 0x2c) < (int)*(short *)(param_1 + 0x25e))) {
    *(undefined1 *)(param_1 + 0x26e) = 5;
    return;
  }
  cVar2 = func_0x80033144(param_1,*(undefined4 *)(param_1 + 0x2c4));
  switch(*(undefined1 *)(param_1 + 0x2cb)) {
  case 1:
  case 2:
  case 3:
  case 0xd:
  case 0x10:
  case 0x12:
  case 0x13:
    *(undefined1 *)(param_1 + 0x26e) = 0;
    break;
  case 4:
  case 0xc:
  case 0xe:
  case 0xf:
    *(undefined1 *)(param_1 + 0x26e) = 1;
    break;
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    goto joined_r0x80165a1c;
  case 10:
    if (cVar2 == '\0') {
LAB_80165a58:
      uVar1 = *(ushort *)(param_1 + 0x26c) & 0xffdf;
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x26c) | 0x20;
    }
    goto LAB_80165a60;
  case 0xb:
joined_r0x80165a1c:
    if (cVar2 == '\0') {
      *(undefined1 *)(param_1 + 0x26e) = 3;
    }
    else {
      *(undefined1 *)(param_1 + 0x26e) = 4;
    }
    break;
  case 0x11:
    if (cVar2 == '\0') goto LAB_80165a58;
    uVar1 = *(ushort *)(param_1 + 0x26c) | 0x20;
LAB_80165a60:
    *(ushort *)(param_1 + 0x26c) = uVar1;
    *(undefined1 *)(param_1 + 0x26e) = 6;
  }
  return;
}
