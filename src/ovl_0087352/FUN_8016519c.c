/* FUN_8016519c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016519c  body 0x8016519c..0x80165283  size 232 B
 * body sha256 4a0c45b5c1769e04d7d48b7d9abdab54315ac2af92c83ff13cb4bf252bd21122
 * provider record sha256 8f2415fb70872339e7421a3a10a03222e44bcb72c91ed8f802b3219695cf8981
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016519c(int param_1)

{
  byte bVar1;
  ushort uVar2;
  
  FUN_80162340();
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 1) {
LAB_80165208:
    uVar2 = *(ushort *)(param_1 + 0x270);
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) | 0x20;
      *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
      goto LAB_80165208;
    }
    if (bVar1 == 2) {
      *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) & 0xffdf;
      *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
    }
    else if (bVar1 != 3) {
      return;
    }
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined2 *)(param_1 + 0x270) = 0;
      goto LAB_80165264;
    }
    uVar2 = _DAT_800e112a;
  }
  if ((uVar2 & 1) == 0) {
    return;
  }
  *(undefined2 *)(param_1 + 0x270) = 0;
LAB_80165264:
  FUN_80165c58(param_1,1,1);
  return;
}
