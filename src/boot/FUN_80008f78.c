/* FUN_80008f78
 * image   boot (boot), base 0x80000480
 * address 0x80008f78  body 0x80008f78..0x80008fdb  size 100 B
 * body sha256 344b9cc317bd849bbfecb28823be2263a50a2d0fec0be5d00096d339288995e5
 * provider record sha256 189d91874a5d8b530226317ff013dfe7e121c276f8441cf80b881e8ee0b813a2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80008f78(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar4 = 0;
  do {
    uVar2 = 7;
    do {
      uVar3 = uVar1 << 1;
      if (iVar4 != 0x20) {
        uVar3 = uVar3 | (int)(uint)*param_1 >> (uVar2 & 0x1f) & 1U;
      }
      uVar2 = uVar2 - 1;
      uVar1 = uVar3 ^ -(uint)((uVar1 & 0x80) != 0) & 0xffffff85;
    } while (-1 < (int)uVar2);
    iVar4 = iVar4 + 1;
    param_1 = param_1 + 1;
  } while (iVar4 < 0x21);
  return uVar1 & 0xff;
}
