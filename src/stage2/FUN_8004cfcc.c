/* FUN_8004cfcc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004cfcc  body 0x8004cfcc..0x8004d02f  size 100 B
 * body sha256 3fa73ce199554bb1cd411b3e50d4d9287bf6883555d2a385f3b8a271570491c1
 * provider record sha256 dfa5bfd0200172db41456d074622a09d3aaba57bfb97aa3d669d5a84b572e23e
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8004cfcc(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = &DAT_8010b6c0;
  do {
    uVar1 = FUN_8008b048(4);
    uVar1 = FUN_8004cf30(uVar1);
    *puVar2 = uVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 4);
  return param_1;
}
