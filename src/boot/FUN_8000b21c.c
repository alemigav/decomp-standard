/* FUN_8000b21c
 * image   boot (boot), base 0x80000480
 * address 0x8000b21c  body 0x8000b21c..0x8000b373  size 344 B
 * body sha256 16cfaaed2f6a998da456184f2dd9a4e1770945ad9ce14c22dbb6965733fc33f8
 * provider record sha256 a64789a3c4ba25d00cf0649df99677082f67dc73e246c50d6e4163b5257fd822
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000b21c(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  ushort auStack_120 [128];
  
  iVar3 = 0xff;
  iVar2 = param_2 + 0xff;
  do {
    *(undefined1 *)(iVar2 + 0x101) = 0;
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar3);
  *(undefined1 *)(param_2 + 0x100) = 0xff;
  uVar6 = 0;
  if (*(char *)(param_1 + 100) != '\0') {
    uVar5 = 0;
    do {
      iVar2 = 1;
      if (uVar5 == 0) {
        iVar2 = *(int *)(param_1 + 0x60);
      }
      iVar3 = FUN_8000a394(param_1,auStack_120,0,uVar5);
      if (iVar3 != 0 && iVar3 != 3) {
        return iVar3;
      }
      if (iVar2 < 0x80) {
        puVar4 = auStack_120 + iVar2;
        do {
          uVar1 = *puVar4;
          iVar2 = iVar2 + 1;
          if ((*(int *)(param_1 + 0x60) <= (int)(uint)uVar1) && (uVar1 >> 8 != uVar5)) {
            iVar3 = param_2 + ((uVar1 & 0xff) >> 2) + (uVar1 >> 8 & 7) * 0x20;
            *(byte *)(iVar3 + 0x101) = *(byte *)(iVar3 + 0x101) | (byte)(1 << (uVar5 & 7));
          }
          puVar4 = puVar4 + 1;
        } while (iVar2 < 0x80);
      }
      uVar6 = uVar6 + 1;
      uVar5 = uVar6 & 0xff;
    } while ((uVar6 & 0xff) < (uint)*(byte *)(param_1 + 100));
  }
  return 0;
}
