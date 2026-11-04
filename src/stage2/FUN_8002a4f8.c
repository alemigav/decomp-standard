/* FUN_8002a4f8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002a4f8  body 0x8002a4f8..0x8002a567  size 112 B
 * body sha256 b3daeb813dc821242c3e37e1e3b0fdaa4bb859439902f3c03223762591c9afa4
 * provider record sha256 41d996a2ec919196518c2c0068b6ee6e4baa5c6110f176354f35efa696b08172
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002a4f8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x48);
  iVar2 = 0;
  *(undefined4 **)(param_1 + 0x178) = puVar1;
  *puVar1 = FUN_800298a0;
  puVar1[1] = FUN_80029fa8;
  do {
    puVar1[0xe] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 < 4);
  return;
}
