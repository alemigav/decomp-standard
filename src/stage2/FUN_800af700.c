/* FUN_800af700
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af700  body 0x800af700..0x800af887  size 392 B
 * body sha256 1052748ac76503e0e5e2bb5a89d97fdeaecdecf17598f9cc5f27ebe97e4f6ddc
 * provider record sha256 937dff15c00a1e1746be9fe28d36a4a984c50ff014e38c313f21cac060646d14
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800af700(int param_1,uint *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *param_2 >> 8;
  if (DAT_80136311 == '\0') {
LAB_800af75c:
    uVar5 = uVar6 & 0xffff;
  }
  else {
    uVar5 = uVar6 & 0xffff;
    if (DAT_80136311 != '*') {
      uVar3 = FUN_800ab3cc(uVar5);
      uVar5 = uVar6 & 0xffff;
      if ((uVar3 & 0x1f) == 0) {
        uVar6 = FUN_800ab3cc(uVar5);
        uVar6 = uVar6 & 0xff;
        goto LAB_800af75c;
      }
    }
  }
  iVar4 = FUN_800ada34(uVar5,&DAT_80158a50);
  if (iVar4 != 0) {
    return 0;
  }
  bVar1 = *(byte *)param_2;
  if (bVar1 == 1) {
    _DAT_80158a58 = (0x7f - (uint)*(ushort *)(param_1 + 0x30)) * param_2[1];
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        _DAT_80158a58 = param_2[1];
      }
      else {
        _DAT_80158a58 = 0;
      }
      goto LAB_800af808;
    }
    if (bVar1 != 2) {
      _DAT_80158a58 = 0;
      goto LAB_800af808;
    }
    _DAT_80158a58 = (uint)*(ushort *)(param_1 + 0x30) * param_2[1];
  }
  _DAT_80158a58 = _DAT_80158a58 / 0x7f;
LAB_800af808:
  if (_DAT_80158a5c <= _DAT_80158a58) {
    _DAT_80158a58 = _DAT_80158a5c - 1;
  }
  FUN_800a54ec(*(undefined1 *)(param_1 + 99),&DAT_80158a50,(*(uint *)(param_1 + 0x24) & 0x200) == 0)
  ;
  *(undefined4 *)(param_1 + 0x5c) = _DAT_80158a50;
  uVar2 = _DAT_80158a54;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x20;
  *(undefined4 *)(param_1 + 0x58) = uVar2;
  return 0;
}
