/* FUN_8006e7e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e7e4  body 0x8006e7e4..0x8006e837  size 84 B
 * body sha256 17b100481152285d57843a6d0f9d98ff4bf00f6eeff47e85da509a239858bf3d
 * provider record sha256 079d9ade62a860c89806ea1c5ebc196d0b09969cd93487dd060964bbda0190b9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006e7e4(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar4 + 1);
  bVar2 = *(byte *)(iVar4 + 2);
  sVar3 = (&DAT_800e8c78)[*(byte *)(iVar4 + 3)];
  *(int *)(param_1 + 0x1c) = iVar4 + 4;
  FUN_8006e838(uVar1,&DAT_800e8c78 + bVar2,(int)sVar3);
  return 1;
}
