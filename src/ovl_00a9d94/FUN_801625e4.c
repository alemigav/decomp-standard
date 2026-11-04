/* FUN_801625e4
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801625e4  body 0x801625e4..0x8016265f  size 124 B
 * body sha256 dd5ecc1b61dc0fc9cf9ca5e8fc0c0f35c006910fe4a147d2f3a6a966901cc0b4
 * provider record sha256 c5774abfb29a53a4230c974dfe6d18daa88429ef8588959c965a868d8cacfdbc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801625e4(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8016c408)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8016c450)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
