/* FUN_80165c74
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165c74  body 0x80165c74..0x80165da7  size 308 B
 * body sha256 b6b188dc345e1764a695a410b4ab236cbe04efa62d3fb77309a36c61e4388952
 * provider record sha256 dd92d5c010ebef3924bf325da0502bd612440b17ac5ed7a57a9a68778712c9d5
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c74(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  uVar5 = *(ushort *)(param_1 + 0x66) & 0xfff;
  if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
    *(undefined1 *)(param_1 + 0x2b9) = 0;
    return;
  }
  bVar1 = *(byte *)(param_1 + 0x2b9);
  if (bVar1 != 0) goto LAB_80165d38;
  if (0xe6 < *(short *)(param_1 + 0x1e0)) {
    local_18 = *(undefined2 *)(param_1 + 0x2a);
    local_16 = *(undefined2 *)(param_1 + 0x2e);
    local_14 = *(undefined2 *)(param_1 + 0x32);
    uVar2 = func_0x8006a42c(&local_18,*(undefined4 *)(param_1 + 0x1b0));
    if ((uVar2 & 0xffff) == 2) {
      if (0xf00 < uVar5 - 0x80) goto LAB_80165d28;
    }
    else {
      iVar3 = (uVar2 & 0xffff) * 0x400;
      if (((iVar3 + 0x780U & 0xfff) < uVar5) && (uVar5 < (iVar3 + 0x880U & 0xfff))) {
LAB_80165d28:
        FUN_80165c68(param_1,10);
      }
    }
  }
  bVar1 = *(byte *)(param_1 + 0x2b9);
LAB_80165d38:
  if (10 < bVar1) {
    uVar5 = func_0x80033604();
    if ((uVar5 & 0x7f) == 0) {
      uVar4 = 7;
    }
    else {
      uVar4 = 8;
    }
    FUN_80165c68(param_1,uVar4);
  }
  if (100 < *(short *)(param_1 + 0x1e0)) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -4;
  }
  *(char *)(param_1 + 0x2b9) = *(char *)(param_1 + 0x2b9) + '\x01';
  return;
}
