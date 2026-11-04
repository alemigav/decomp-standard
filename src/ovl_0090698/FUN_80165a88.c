/* FUN_80165a88
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165a88  body 0x80165a88..0x80165b6b  size 228 B
 * body sha256 88b240fe2c37f9a8b7899f1150b820f465d456ef4c5ffe3352f94aa51b569467
 * provider record sha256 4867487f0068d89ab594e6a02017f46620155c97925b651ab35f4ec0f47df8de
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80165a88(int param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  short local_20;
  undefined2 local_1e;
  short local_1c;
  
  if (*(char *)(param_1 + 0x2d2) != '\0') {
    _DAT_800e1128 = _DAT_800e1128 & 0xffdf;
  }
  uVar2 = 0;
  if (*(char *)(param_1 + 0x2d6) < '\x01') {
    iVar3 = *(int *)(param_1 + 0x234);
    psVar1 = &DAT_80167f84;
    do {
      uVar2 = uVar2 + 1;
      local_20 = *(short *)(iVar3 + 0x4e) + *psVar1;
      local_1e = *(undefined2 *)(param_1 + 0x1a8);
      local_1c = *(short *)(iVar3 + 0x56) + psVar1[2];
      psVar1 = psVar1 + 4;
      func_0x80037780(0x1a002000,(int)*(short *)(param_1 + 0x66),0x800e9028,&local_20);
    } while (uVar2 < 8);
    *(undefined1 *)(param_1 + 0x2da) = 1;
    *(undefined1 *)(param_1 + 0x2db) = 1;
  }
  return;
}
