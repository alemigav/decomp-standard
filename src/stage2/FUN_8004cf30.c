/* FUN_8004cf30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cf30  body 0x8004cf30..0x8004cfcb  size 156 B
 * body sha256 cc0fe2d6e15928d693f22857dd059ad326e105cfe776ffe4a006577bcde489b9
 * provider record sha256 92d82059de379263e905db6f21e9144c12dbe7e855be83f9b7548b0dd0074319
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004cf30(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)FUN_8008b048(0x10);
  *puVar1 = 300;
  iVar2 = FUN_8008b0ec(0x4b0);
  iVar3 = 299;
  iVar4 = iVar2;
  do {
    FUN_8004d184(iVar4 + 2);
    iVar3 = iVar3 + -1;
    iVar4 = iVar4 + 4;
  } while (iVar3 != -1);
  puVar1[1] = iVar2;
  FUN_8004d178(puVar1);
  *param_1 = puVar1;
  return;
}
