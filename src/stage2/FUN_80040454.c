/* FUN_80040454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040454  body 0x80040454..0x800404d7  size 132 B
 * body sha256 34487c2294c23886cb80ed41721664ea72f69b8d43d6248691c19326327c0506
 * provider record sha256 df59c5a79d23281b3edd78d6f2c4d0f25d4c96551fec8088eb0d4df9ec119d49
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80040454(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  if ((iVar2 != 0) && (iVar2 < *(short *)(DAT_800ebb94 + 0x36))) {
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a050000,(int)*(short *)(DAT_800ebb94 + 0x22),
                 &DAT_800e9028,DAT_800ebb94 + 0x34);
  }
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  return;
}
