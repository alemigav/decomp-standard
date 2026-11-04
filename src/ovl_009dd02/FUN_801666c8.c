/* FUN_801666c8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801666c8  body 0x801666c8..0x80166837  size 368 B
 * body sha256 52a0bfe3982c9bb283127a1ba52bcf3b29d5cb70e4f614f796c207c7760632e7
 * provider record sha256 100b0cd724829e3eba1c34012266b47dec75f42e780c8bddc64cf18ce01d58f1
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_801666c8(int param_1,undefined1 *param_2,int param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  byte bVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x2d4) >> 0xf;
  iVar2 = func_0x80033024(param_2 + 0x28,*(int *)(param_1 + 0x234) + param_3 * 0x178 + 0x4c,param_4)
  ;
  if (iVar2 == 0) {
    return 0;
  }
  if ((param_2[0x26f] & 0x80) != 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x1a2) != param_2[0x1a2]) {
    return 0;
  }
  if (*(short *)(param_2 + 0x1f2) < 0) goto LAB_80166810;
  if (param_2 == &DAT_800e1130) {
    iVar2 = func_0x80059e00(*(undefined1 *)(param_1 + 0x2b9),uVar1);
  }
  else {
    iVar2 = func_0x80080e00(param_1,*(undefined1 *)(param_1 + 0x2b9),uVar1);
  }
  if (iVar2 == 1) {
    _DAT_800e1128 = _DAT_800e1128 | 0x20;
  }
  else {
    if (1 < iVar2) {
      if (iVar2 == 2) {
        FUN_80166960(param_2);
      }
      goto LAB_80166810;
    }
    if (iVar2 != 0) goto LAB_80166810;
  }
  bVar3 = func_0x80033144(param_1,param_2);
  FUN_80166908(param_2,*(byte *)(param_1 + 0x2cd) ^ bVar3);
LAB_80166810:
  func_0x80077d18(1,param_1);
  return 1;
}
