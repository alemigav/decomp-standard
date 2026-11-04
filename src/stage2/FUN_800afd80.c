/* FUN_800afd80
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800afd80  body 0x800afd80..0x800affdb  size 604 B
 * body sha256 f909b8810997567ac3d3581fe0ba0ec603e179212c66fa27f960739fa2d86426
 * provider record sha256 f3cf4d5d4332a73f99435674d858cef23d2c997df959c6d7a1a03118892970f5
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800afd80(int param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (*(byte *)((int)param_2 + 6) == 0) {
    uVar5 = *param_2 >> 8;
    uVar3 = *param_2 >> 0x18;
    uVar6 = uVar3;
    if (uVar3 < (uVar5 & 0xff)) {
      uVar6 = uVar5;
      uVar5 = uVar3;
    }
  }
  else {
    uVar3 = (uint)*(ushort *)(param_1 + 0x50) + (uint)*(byte *)param_2;
    uVar6 = (uint)*(ushort *)(param_1 + 0x50) - (uint)*(byte *)((int)param_2 + 2);
    iVar4 = (int)(uVar6 * 0x10000) >> 0x10;
    if (iVar4 < 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0x7f;
      if (iVar4 < 0x80) {
        uVar5 = uVar6;
      }
    }
    iVar4 = (int)(uVar3 * 0x10000) >> 0x10;
    if (iVar4 < 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x7f;
      if (iVar4 < 0x80) {
        uVar6 = uVar3;
      }
    }
  }
  if (*(byte *)((int)param_2 + 7) == 0) {
    uVar3 = (uint)*(byte *)((int)param_2 + 1);
  }
  else {
    uVar3 = FUN_800ab3cc();
    uVar3 = (uVar3 & 0xffff) % 0xc9 - 100;
  }
  uVar2 = FUN_800ab3cc();
  iVar4 = ((uVar6 & 0xff) - (uVar5 & 0xff)) + 1;
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && ((uVar2 & 0xffff) == 0x80000000)) {
    trap(0x1800);
  }
  param_2[1] = 0;
  uVar6 = ((uVar5 & 0xff) + (int)(uVar2 & 0xffff) % iVar4) * 0x100;
  *param_2 = (uVar3 & 0xff) << 0x10 | uVar6 | 0x19;
  *(ushort *)(param_1 + 0x50) = (ushort)(uVar6 >> 8) & 0x7f;
  *(char *)(param_1 + 0xc0) = (char)*(undefined2 *)param_2;
  if (*(int *)(param_1 + 0x60) != -1) {
    bVar1 = false;
    if (*(char *)(param_1 + 0x4a) == -1) goto LAB_800aff84;
    uVar6 = (uint)*(byte *)(param_1 + 99);
    if (*(char *)(param_1 + 0x4b) == -1) {
      bVar1 = false;
      if (*(byte *)(uVar6 + 0x80158a80) == uVar6) {
        bVar1 = true;
      }
      goto LAB_800aff84;
    }
    bVar1 = true;
    if (*(byte *)((uint)*(byte *)(param_1 + 0x4a) + (uint)*(byte *)(param_1 + 0x4b) * 0x10 +
                 -0x7fea7560) == uVar6) goto LAB_800aff84;
  }
  bVar1 = false;
LAB_800aff84:
  if (bVar1) {
    FUN_800ac69c(*(undefined1 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b),
                 *(undefined1 *)(param_1 + 0x51));
  }
  *param_2 = 4;
  FUN_800af1b0(param_1,param_2);
  return 0;
}
