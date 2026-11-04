/* FUN_80180b10
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80180b10  body 0x80180b10..0x80180be3  size 212 B
 * body sha256 2f9802e9832cdeeb95cde1c2a936311381794d1f2ac08936b6e6feb0aba2e5d1
 * provider record sha256 fcfd03347659de000a32b690f525b8e5e1bc9249e8d97e421085beb9af365f5c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80180b10(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  FUN_80180a20(*(undefined2 *)(_DAT_801344b0 * 0x112 + -0x7fecbae8),
               *(undefined2 *)(_DAT_801344b0 * 0x112 + -0x7fecbae6));
  puVar2 = (undefined4 *)&DAT_80112978;
  puVar1 = (undefined4 *)&DAT_801129c8;
  do {
    uVar3 = puVar1[1];
    uVar4 = puVar1[2];
    uVar5 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
    puVar1 = puVar1 + 4;
    puVar2 = puVar2 + 4;
  } while (puVar1 != (undefined4 *)0x80112a18);
  func_0x8000e980(&DAT_80112978);
  func_0x8000e9d0(2);
  func_0x8000e9d0(8);
  func_0x8000e9d0(0x20);
  func_0x8000e9d0(0x40);
  return;
}
