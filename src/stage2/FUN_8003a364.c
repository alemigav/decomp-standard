/* FUN_8003a364
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a364  body 0x8003a364..0x8003a577  size 532 B
 * body sha256 4f35155d0e3b5b913ab6010a99041800d087af3ec95ba143c5ba35e643271bfe
 * provider record sha256 6382bf8f991ce8bbb769af8060df99d97fb5e30aaceb6dab049a5d53813ec70e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a364(void)

{
  ushort *puVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (*(char *)(DAT_800ebb94 + 0xb) == '\0') {
    if (*(char *)(DAT_800ebb94 + 0x21) == *(char *)(DAT_800ebb94 + 2)) {
      uVar4 = FUN_80038a20((uint)*(byte *)(DAT_800ebb94 + 0x1c) << 0x18 |
                           (uint)*(byte *)(DAT_800ebb94 + 0x1e) << 0x10 |
                           (uint)*(ushort *)(DAT_800ebb94 + 0x3a),
                           (int)*(short *)(DAT_800ebb94 + 0x22),*(undefined4 *)(DAT_800ebb94 + 0x6c)
                           ,DAT_800ebb94 + 0x2c);
      if ((uVar4 & 0xff) < 0xff) {
        iVar3 = (uVar4 & 0xff) * 0x7c;
        (&DAT_800ebdc5)[iVar3] = *(undefined1 *)(DAT_800ebb94 + 0x1d);
        (&DAT_800ebdc3)[iVar3] = *(undefined1 *)(DAT_800ebb94 + 0x1b);
      }
    }
  }
  else {
    if ((*(char *)(DAT_800ebb94 + 0x1b) < '\n') &&
       (*(char *)(DAT_800ebb94 + 0x21) == *(char *)(DAT_800ebb94 + 2))) {
      *(char *)(DAT_800ebb94 + 0x1b) = *(char *)(DAT_800ebb94 + 0x1b) + '\x01';
      if (*(char *)(DAT_800ebb94 + 0x1b) < '\x06') {
        sVar2 = *(short *)(DAT_800ebb94 + 0x22);
        uVar5 = *(undefined4 *)(DAT_800ebb94 + 0x6c);
        uVar4 = (uint)*(byte *)(DAT_800ebb94 + 0x1c) << 0x18 |
                (uint)*(byte *)(DAT_800ebb94 + 0x1e) << 0x10 |
                (uint)*(ushort *)(DAT_800ebb94 + 0x3a);
      }
      else {
        sVar2 = *(short *)(DAT_800ebb94 + 0x22);
        uVar5 = *(undefined4 *)(DAT_800ebb94 + 0x6c);
        uVar4 = (uint)*(byte *)(DAT_800ebb94 + 0x1c) << 0x18 |
                (uint)*(byte *)(DAT_800ebb94 + 0x1e) << 0x10 |
                ((uint)*(ushort *)(DAT_800ebb94 + 0x3a) * 800) / 1000;
      }
      uVar4 = FUN_80038a20(uVar4,(int)sVar2,uVar5,DAT_800ebb94 + 0x2c);
      if ((uVar4 & 0xff) < 0xff) {
        iVar3 = (uVar4 & 0xff) * 0x7c;
        (&DAT_800ebdc5)[iVar3] = *(undefined1 *)(DAT_800ebb94 + 0x1d);
        (&DAT_800ebdc3)[iVar3] = *(undefined1 *)(DAT_800ebb94 + 0x1b);
      }
    }
    iVar3 = DAT_800ebb94;
    if (0x12 < *(byte *)(DAT_800ebb94 + 0x21)) {
      puVar1 = (ushort *)(DAT_800ebb94 + 0x3a);
      *(undefined1 *)(DAT_800ebb94 + 9) = 0;
      *(short *)(iVar3 + 0x3a) = (short)(((uint)*puVar1 * 0x3d4) / 1000);
    }
    if (0x14 < *(byte *)(DAT_800ebb94 + 0x21)) {
      *(undefined2 *)(DAT_800ebb94 + 0xe) = 0;
    }
  }
  return;
}
