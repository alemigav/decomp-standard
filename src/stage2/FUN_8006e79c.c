/* FUN_8006e79c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e79c  body 0x8006e79c..0x8006e7e3  size 72 B
 * body sha256 53686e9895b55a9c69a1eeede57450db704af09d7296882edaec9c473256853f
 * provider record sha256 0adfda1602609adb7b8877475e3615453890ac1f6cda7c457ffa07467399f172
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006e79c(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar4 + 2);
  bVar2 = *(byte *)(iVar4 + 3);
  sVar3 = *(short *)(iVar4 + 4);
  *(int *)(param_1 + 0x1c) = iVar4 + 6;
  FUN_8006e838(uVar1,&DAT_800e8c78 + bVar2,(int)sVar3);
  return 1;
}
