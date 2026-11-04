/* FUN_80166b0c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166b0c  body 0x80166b0c..0x80166c7b  size 368 B
 * body sha256 d35e5672e176074a149d062d98f6d7ded9f9f01d994cf38120c6d15637679d39
 * provider record sha256 09320bec4cdf9e5a7d5baa7cabf0a695c5d0831d3496b0a18cd1cc72dcfebdcd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166b0c(int param_1)

{
  char cVar3;
  ushort uVar2;
  uint uVar1;
  
  uVar2 = *(ushort *)(param_1 + 0x2c8);
  if ((uVar2 & 0x40) != 0) {
    *(undefined1 *)(param_1 + 0x26e) = 0;
    return;
  }
  if ((uVar2 & 0x200) != 0) {
    *(undefined1 *)(param_1 + 0x26e) = 7;
    return;
  }
  if ((*(int *)(param_1 + 700) != 0) ||
     (*(int *)(param_1 + 0x2c) < (int)*(short *)(param_1 + 0x25e))) {
    if ((uVar2 & 0x80) == 0) {
      *(undefined1 *)(param_1 + 0x26e) = 2;
      return;
    }
    *(undefined1 *)(param_1 + 0x26e) = 5;
    return;
  }
  cVar3 = func_0x80033144(param_1,*(undefined4 *)(param_1 + 0x2c4));
  switch(*(undefined1 *)(param_1 + 0x2cb)) {
  case 1:
  case 2:
  case 3:
  case 0xd:
  case 0x10:
  case 0x12:
  case 0x13:
    *(undefined1 *)(param_1 + 0x26e) = 0;
    return;
  case 4:
  case 0xc:
  case 0xe:
  case 0xf:
    goto LAB_80166c30;
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    uVar1 = func_0x80033604();
    break;
  case 10:
    if (cVar3 == '\0') {
LAB_80166c4c:
      uVar2 = *(ushort *)(param_1 + 0x26c) & 0xffdf;
    }
    else {
      uVar2 = *(ushort *)(param_1 + 0x26c) | 0x20;
    }
    goto LAB_80166c54;
  case 0xb:
    uVar1 = func_0x80033604();
    break;
  case 0x11:
    if (cVar3 == '\0') goto LAB_80166c4c;
    uVar2 = *(ushort *)(param_1 + 0x26c) | 0x20;
LAB_80166c54:
    *(ushort *)(param_1 + 0x26c) = uVar2;
    *(undefined1 *)(param_1 + 0x26e) = 6;
  default:
    goto switchD_80166bb4_default;
  }
  if ((uVar1 & 0xf) < 5) {
LAB_80166c30:
    *(undefined1 *)(param_1 + 0x26e) = 1;
  }
  else if (cVar3 == '\0') {
    *(undefined1 *)(param_1 + 0x26e) = 3;
  }
  else {
    *(undefined1 *)(param_1 + 0x26e) = 4;
  }
switchD_80166bb4_default:
  return;
}
