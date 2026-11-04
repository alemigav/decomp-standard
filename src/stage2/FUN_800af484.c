/* FUN_800af484
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af484  body 0x800af484..0x800af5c3  size 320 B
 * body sha256 ccd48eeae67eb29ec6e9da43872a2e3d818460173af861ef5663cb7048af2a09
 * provider record sha256 961e2f45ecb0c13dc593cd3b7b778cc8b65c16cf5162f23df08d1885a2217fe8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800af484(int param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *param_2;
  uVar5 = (uint)*(ushort *)(param_1 + 0x4e) + ((int)(uVar4 << 0x10) >> 0x18);
  bVar1 = *(byte *)((int)param_2 + 5);
  bVar2 = *(byte *)(param_2 + 1);
  if ((int)uVar5 < 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0x7f;
    if ((int)uVar5 < 0x80) {
      uVar6 = uVar5;
    }
  }
  if (*(char *)(param_1 + 0x4c) != '\0') {
    uVar6 = uVar6 | 0x80;
  }
  *(undefined1 *)(param_1 + 0xbd) = 1;
  uVar4 = FUN_800b185c(uVar4 & 0xffff0000 | (uint)bVar1 << 8 | (uint)bVar2,
                       *(undefined2 *)(param_1 + 0xba),uVar6 & 0xff,*(undefined1 *)(param_1 + 0x31),
                       *(undefined1 *)(param_1 + 0x39),*(undefined1 *)(param_1 + 0x4a),
                       *(undefined1 *)(param_1 + 0x4b),*(undefined2 *)((int)param_2 + 6),
                       *(undefined1 *)(param_1 + 0x2f),0,*(undefined1 *)(param_1 + 0xbe));
  *(undefined1 *)(param_1 + 0xbd) = 0;
  if (uVar4 != 0xffffffff) {
    iVar3 = (uVar4 & 0xff) * 0x1a0;
    *(undefined4 *)(iVar3 + -0x7febbba4) = *(undefined4 *)(param_1 + 0x60);
    if (*(int *)(param_1 + 0x10) == -1) {
      *(uint *)(param_1 + 0x10) = uVar4;
    }
    else {
      *(int *)(iVar3 + -0x7febbba8) = *(int *)(param_1 + 0x10);
      *(uint *)((uint)*(byte *)(param_1 + 0x13) * 0x1a0 + -0x7febbba4) = uVar4;
      *(uint *)(param_1 + 0x10) = uVar4;
    }
  }
  return 0;
}
