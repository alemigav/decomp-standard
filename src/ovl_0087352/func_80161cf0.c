/* func_80161cf0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161e13  size 292 B
 * body sha256 4553cd9f798b50a36abe817d63a204813c839277d91c8d8ce86184340f29e63a
 * provider record sha256 842401164623c89811b4c2dcd636720bcfa87e787a18ca482afdc001b6a456f9
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int iVar1;
  ushort uVar2;
  int in_a0;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    if ((*(byte *)(in_a0 + 0x26f) & 0x7f) != 0) {
      *(byte *)(in_a0 + 0x26f) = *(byte *)(in_a0 + 0x26f) - 1;
    }
    local_28 = *(undefined4 *)(in_a0 + 0x28);
    local_24 = *(undefined4 *)(in_a0 + 0x2c);
    local_20 = *(undefined4 *)(in_a0 + 0x30);
    local_10 = _DAT_800e1160;
    local_18 = _DAT_800e1158;
    local_14 = _DAT_800e115c;
    iVar1 = func_0x8006ab40(&local_28,&local_18,0x8400,0);
    if (iVar1 == 0) {
      uVar2 = *(ushort *)(in_a0 + 0x2c6) | 2;
    }
    else {
      uVar2 = *(ushort *)(in_a0 + 0x2c6) & 0xfffd;
    }
    *(ushort *)(in_a0 + 0x2c6) = uVar2;
    if (*(uint *)(in_a0 + 0x28c) < 900) {
      *(undefined2 *)(in_a0 + 0x134) = 0xfea2;
    }
    else {
      *(undefined2 *)(in_a0 + 0x134) = 0;
    }
    (*(code *)(&PTR_FUN_80166570)[*(byte *)(in_a0 + 4)])();
    FUN_80161e14();
    FUN_8016601c();
    func_0x8004db5c();
    func_0x8004dcb8();
  }
  return;
}
