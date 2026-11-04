/* FUN_800559b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800559b0  body 0x800559b0..0x80055c13  size 612 B
 * body sha256 95e9acb9e703ded86f892e927d55f8b043a4a3b876e6c8abb69de4bc6949bb5a
 * provider record sha256 81534afbffbbf6c48c61dde26b9dbeb8ea3ddd329c46c06cb3cdc090d6a91a2e
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x800559cc) */

void FUN_800559b0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (-1 < DAT_800e1110) {
    DAT_800e110c = DAT_800e110c & 0xffffff7f;
    DAT_800e112a = DAT_800e112a & 0xffe0;
    if ((*(byte *)(param_1 + 0x26f) & 0x7f) != 0) {
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) - 1;
    }
    if (*(char *)(param_1 + 8) == '\r') {
      iVar3 = (int)*(short *)(param_1 + 0x1fe);
      iVar1 = (int)*(short *)(param_1 + 0x1f2) << 0xf;
      if (iVar3 == 0) {
        trap(0x1c00);
      }
      if ((iVar3 == -1) && (iVar1 == -0x80000000)) {
        trap(0x1800);
      }
      iVar4 = *(int *)(param_1 + 0x234);
      uVar2 = (uint)(iVar1 / iVar3) >> 8;
      uVar2 = uVar2 << 0x10 | uVar2 << 8;
      *(uint *)(iVar4 + 0x60) = uVar2 + 0x80;
      *(uint *)(iVar4 + 0xcc) = uVar2 | 0x800000ff;
      if (*(short *)(param_1 + 0x1f2) < 0) {
        *(undefined4 *)(iVar4 + 0x60) = 0x80;
        *(undefined4 *)(iVar4 + 0xcc) = 0x800000ff;
      }
      if (DAT_800e13e4 == 0) {
        if ((DAT_8010dc01 != 0) && ((*(byte *)(param_1 + 0x1e9) & 1) == 0)) {
          DAT_8010dc01 = DAT_8010dc01 - 1;
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x1e9) & 1) == 0) {
          DAT_8010dc01 = DAT_8010dc01 + 1;
        }
        if (0x40 < DAT_8010dc01) {
          DAT_8010dc01 = 0x40;
        }
      }
      *(uint *)(iVar4 + 0x60) = *(int *)(iVar4 + 0x60) + (uint)DAT_8010dc01 * 0x10000;
    }
    if ((DAT_800e13e4 != 0) && (DAT_800e13e6 = DAT_800e13e6 + -1, DAT_800e13e6 == -1)) {
      DAT_800e13e6 = '\x1e';
      if (1 < *(short *)(param_1 + 0x1f2)) {
        *(short *)(param_1 + 0x1f2) = *(short *)(param_1 + 0x1f2) + -1;
      }
    }
    (*(code *)(&PTR_FUN_8010dc10)[*(byte *)(param_1 + 4)])
              (param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218));
    FUN_80057718(param_1,7000,0x5dc);
    FUN_80034280(param_1,(int)*(short *)(param_1 + 0x66));
    if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0xc) {
      FUN_8005fce0(param_1);
    }
    FUN_8005c27c(param_1);
    FUN_8005c32c(param_1);
    FUN_8005c03c(param_1);
  }
  return;
}
