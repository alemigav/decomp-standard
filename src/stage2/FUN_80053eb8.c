/* FUN_80053eb8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053eb8  body 0x80053eb8..0x80054083  size 460 B
 * body sha256 6c8b0257c3cf3676d6553fcdf4c65db14a8b51b5dd00bba09f85b9fd391d31ec
 * provider record sha256 8ff08c21c7e8f2c7c65df4d0c53b70d451ad655bbecc4f5cc96df4a5ad236501
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80053eb8(int param_1)

{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  FUN_80043620();
  iVar1 = DAT_8010d940;
  piVar5 = (int *)(DAT_8010d940 + (uint)DAT_800dfbe8 * 0x1c70 + 0x19c0);
  piVar4 = (int *)(DAT_8010d940 + 0x300);
  piVar7 = piVar4 + param_1 * 4;
  piVar6 = (int *)(DAT_8010d940 + 800);
  pbVar3 = (byte *)(DAT_8010d940 + 0x30d);
  piVar2 = piVar5 + 3;
  do {
    if (pbVar3[2] != 0) {
      *piVar5 = (uint)*pbVar3 * 0x1000000 + (uint)pbVar3[1] * 0x10101 + 0x64000000;
      piVar2[-2] = *piVar4;
      piVar2[1] = *(int *)(pbVar3 + -9);
      piVar2[-1] = *(int *)(pbVar3 + -5);
      if (*pbVar3 == 0) {
        *(undefined1 *)((int)piVar2 + -9) = 0;
      }
      else {
        *(undefined1 *)((int)piVar2 + -9) = 2;
      }
      *piVar2 = (int)&DAT_8010d944;
      if (piVar4 == piVar6) {
        local_40 = *piVar5;
        local_3c = piVar5[1];
        local_38 = piVar5[2];
        local_34 = piVar5[3];
        local_30 = piVar5[4];
      }
      else {
        DAT_800df8b0 = FUN_80043988(DAT_800df8b0,piVar5,0,0);
      }
      piVar2 = piVar2 + 5;
      piVar5 = piVar5 + 5;
    }
    piVar4 = piVar4 + 4;
    pbVar3 = pbVar3 + 0x10;
  } while (piVar4 < piVar7);
  if (*(char *)(iVar1 + 0x32f) != '\0') {
    DAT_800df8b0 = FUN_80043988(DAT_800df8b0,&local_40,0,0);
  }
  FUN_800540d4();
  return;
}
