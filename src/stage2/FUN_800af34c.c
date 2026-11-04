/* FUN_800af34c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af34c  body 0x800af34c..0x800af483  size 312 B
 * body sha256 7b8b9c35675ecaa764da44e36356d9dea01984ee7237a52c767eac08d2acb4c0
 * provider record sha256 e707f3e1d45c7a779da394ece7da83bb48d12921c31fc2260e6e38c8518d912d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800af34c(int *param_1,uint *param_2)

{
  short sVar1;
  uint uVar2;
  char cVar3;
  
  if (*(short *)(param_1 + 0x1a) == 0) {
    if ((*param_2 & 0x10000) == 0) {
      *(ushort *)(param_1 + 0x1a) = *(ushort *)(param_2 + 1);
    }
    else {
      uVar2 = FUN_800ab3cc();
      if (*(ushort *)(param_2 + 1) == 0) {
        trap(0x1c00);
      }
      *(short *)(param_1 + 0x1a) = (short)((uVar2 & 0xffff) % (uint)*(ushort *)(param_2 + 1));
    }
    if (*(short *)(param_1 + 0x1a) == -1) goto LAB_800af3ec;
    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 1;
  }
  else if (*(short *)(param_1 + 0x1a) == -1) goto LAB_800af3ec;
  sVar1 = *(short *)(param_1 + 0x1a);
  *(short *)(param_1 + 0x1a) = sVar1 + -1;
  if ((short)(sVar1 + -1) == 0) {
    return 0;
  }
LAB_800af3ec:
  if (((*param_2 >> 8 & 1) == 0) || ((param_1[9] & 0x40000008U) != 8)) {
    if (((*param_2 & 0x1000000) == 0) ||
       (((param_1[9] & 0x20U) != 0 ||
        (cVar3 = FUN_800a5890(*(undefined1 *)((int)param_1 + 99)), cVar3 != '\0')))) {
      param_1[1] = *param_1 + (uint)*(ushort *)((int)param_2 + 6) * 8;
    }
    else {
      *(undefined2 *)(param_1 + 0x1a) = 0;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x1a) = 0;
  }
  return 0;
}
