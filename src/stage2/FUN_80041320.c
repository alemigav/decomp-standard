/* FUN_80041320
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80041320  body 0x80041320..0x80041453  size 308 B
 * body sha256 19dbc3d5a86828e27f06eb22951ab03f336165e033ccded20dae119cd8d43b5c
 * provider record sha256 20ddd90781b9a091d54dd8ec0de5c15019cc179552864603290ed2d3ab55676d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80041320(undefined4 param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = FUN_800408c0();
  iVar5 = FUN_80040968(param_1);
  sVar1 = *(short *)(param_2 + 6);
  sVar2 = *(short *)(param_2 + 8);
  sVar3 = *(short *)(param_2 + 10);
  *(short *)(param_2 + 6) = (short)(sVar1 * iVar4 - *(short *)(param_2 + 0xc) * iVar5 >> 0xc);
  *(short *)(param_2 + 0xc) = (short)(sVar1 * iVar5 + *(short *)(param_2 + 0xc) * iVar4 >> 0xc);
  *(short *)(param_2 + 8) = (short)(sVar2 * iVar4 - *(short *)(param_2 + 0xe) * iVar5 >> 0xc);
  *(short *)(param_2 + 0xe) = (short)(sVar2 * iVar5 + *(short *)(param_2 + 0xe) * iVar4 >> 0xc);
  *(short *)(param_2 + 10) = (short)(sVar3 * iVar4 - *(short *)(param_2 + 0x10) * iVar5 >> 0xc);
  *(short *)(param_2 + 0x10) = (short)(sVar3 * iVar5 + *(short *)(param_2 + 0x10) * iVar4 >> 0xc);
  return;
}
