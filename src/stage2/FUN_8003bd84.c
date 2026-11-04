/* FUN_8003bd84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bd84  body 0x8003bd84..0x8003be37  size 180 B
 * body sha256 c5b2c0d838bfd688da6943b357280605f1c18d8007846f8c6c3d66b9fb11bd5e
 * provider record sha256 ff007a580faaa2cae1129bb3efe85d8ca1e3d66b5161b860c5f04d365f6c5270
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003bd84(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  
  if (*(char *)(DAT_800ebb94 + 3) == '\0') {
    *(undefined2 *)(DAT_800ebb94 + 0x18) = 0xb803;
    bVar3 = FUN_80033604();
    *(byte *)(DAT_800ebb94 + 3) = bVar3 % 0x1e + 0x3c;
  }
  else {
    *(char *)(DAT_800ebb94 + 3) = *(char *)(DAT_800ebb94 + 3) + -1;
    iVar1 = DAT_800ebb94;
    if (*(char *)(DAT_800ebb94 + 0x21) == '\x12') {
      *(undefined1 *)(DAT_800ebb94 + 0x21) = 0xb;
      iVar2 = DAT_800ebb94;
      *(undefined2 *)(iVar1 + 0x18) = 0x8000;
      *(undefined1 *)(iVar2 + 0x20) =
           *(undefined1 *)(*(int *)(iVar2 + 0x70) + (uint)*(byte *)(iVar2 + 0x21) * 8 + 2);
    }
  }
  return;
}
