/* FUN_801668b4
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801668b4  body 0x801668b4..0x801669f7  size 324 B
 * body sha256 639dce054eccd9a6d188eb33cf30dc78570d7c9348b51812eada1527f83832c0
 * provider record sha256 8ff1e2d09784ec6d4ba3f588137ec4741b9a7cc1a59b75bab7277e67f01f1450
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801668b4(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  
  if (*(char *)(param_1 + 0x2da) != '\0') {
    if (*(short *)(param_1 + 0x1a8) == 0) {
      *(undefined1 *)(param_1 + 0x2d6) = 1;
      *(undefined1 *)(param_1 + 0x2db) = 0;
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      return;
    }
    bVar1 = *(byte *)(param_1 + 0x2da);
    if (bVar1 != 2) {
      if (2 < bVar1) {
        if (bVar1 == 3) {
          uVar2 = *(ushort *)(param_1 + 0x1f6);
          *(ushort *)(param_1 + 0x1f6) = uVar2 + 1;
          *(uint *)(param_1 + 0x2c) =
               (int)*(short *)(param_1 + 0x1a8) + (byte)(&DAT_80167fec)[(uVar2 & 0x3f) >> 3] + 0x46;
          return;
        }
        return;
      }
      if (bVar1 != 1) {
        return;
      }
      *(undefined1 *)(param_1 + 0x2da) = 2;
      *(undefined2 *)(param_1 + 0x1e2) = 0x8c;
      *(undefined2 *)(param_1 + 0x2e0) = 0;
    }
    sVar3 = *(short *)(param_1 + 0x2e0) + *(short *)(param_1 + 0x1e2);
    *(short *)(param_1 + 0x2e0) = sVar3;
    sVar4 = *(short *)(param_1 + 0x1e2) + -0xf;
    *(short *)(param_1 + 0x1e2) = sVar4;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x1a8) + sVar3 + 0x46;
    if (sVar4 < 1) {
      if (sVar4 < -0x46) {
        *(undefined2 *)(param_1 + 0x1e2) = 0xffba;
      }
      if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(param_1 + 0x2c)) {
        return;
      }
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x1a8);
      *(undefined1 *)(param_1 + 0x2da) = 3;
      return;
    }
    if ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c)) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      return;
    }
  }
  return;
}
