/* FUN_8008c05c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c05c  body 0x8008c05c..0x8008c193  size 312 B
 * body sha256 15b238899d777545ac2ef7fe65b4f10d0be9e56cb588a27e6e362de6a03c91df
 * provider record sha256 9841bfd7a4fd2683d4e91d4422a0163c025cc159b29d2e8c99a1121c95326bac
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8008c05c(int param_1)

{
  byte bVar2;
  byte bVar3;
  undefined4 *puVar1;
  uint uVar4;
  char cVar5;
  
  cVar5 = (char)param_1;
  if (param_1 - 0x19U < 0x10) {
    bVar2 = DAT_800e901b + 1;
    if (DAT_800e901b == 0xff) {
      DAT_800e901b = 1;
    }
    else {
      bVar3 = DAT_800e901b + 1;
      DAT_800e901b = bVar2;
      if (0x10 < bVar3) {
        FUN_8004cdd4();
        return 0;
      }
    }
    uVar4 = (int)(DAT_800e901b - 1) / 2;
    if (((int)(DAT_800e901b - 1) % 2 & 0xffU) == 0) {
      uVar4 = uVar4 & 0xff;
      (&DAT_800e9013)[uVar4] = (&DAT_800e9013)[uVar4] & 0xf | (cVar5 + -0x19) * '\x10';
    }
    else {
      uVar4 = uVar4 & 0xff;
      (&DAT_800e9013)[uVar4] = (&DAT_800e9013)[uVar4] & 0xf0 | cVar5 - 0x19U;
    }
    uVar4 = DAT_800e901b - 1;
  }
  else {
    puVar1 = &DAT_800c76b0;
    uVar4 = 0;
    while (*(char *)(puVar1 + 0x8651) != -1) {
      if (0x17 < uVar4 + 1) {
        return 0;
      }
      puVar1 = (undefined4 *)(uVar4 + 0x800c76b1);
      uVar4 = uVar4 + 1;
    }
    *(char *)(puVar1 + 0x8651) = cVar5;
  }
  return uVar4;
}
