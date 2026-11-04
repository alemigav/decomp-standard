/* FUN_80009c30
 * image   boot (boot), base 0x80000480
 * address 0x80009c30  body 0x80009c30..0x80009c67  size 56 B
 * body sha256 d69fac0f0a4f782a417b0c6a82697dc7dee92228fa40367149f0c1974bd88826
 * provider record sha256 1216b670f4b69cf5e2937d44f25455d12f74ef9a014ebf18fe499bfe31a3aace
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
short FUN_80009c30(byte *param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = 0;
  sVar2 = 0;
  if (0 < param_2) {
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 1;
      sVar2 = sVar2 + (ushort)bVar1;
    } while (iVar3 < param_2);
  }
  return sVar2;
}
