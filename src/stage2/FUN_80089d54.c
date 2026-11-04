/* FUN_80089d54
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089d54  body 0x80089d54..0x80089dc7  size 116 B
 * body sha256 bedf9c7f4c786561e0e921bfedfd701d393ef28311a54a930e69d62ff89d587a
 * provider record sha256 c3a8ac9b91f6d228847bc20adaeb1c7040a0e9e77248cbaf31bd7d0023facaca
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80089d54(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_3 + (uint)*(byte *)(param_1 + 0x1e8) * 4);
  if ((param_4 & 0xffff0000) == 0) {
    uVar1 = (uint)*(byte *)(param_1 + 0x1e9);
  }
  else {
    uVar1 = ((uVar2 & 0xffff) - (uint)*(byte *)(param_1 + 0x1e9)) - 1;
  }
  *(uint *)(param_1 + 0x214) = param_3 + (uVar2 >> 0x10) + uVar1 * 4;
  FUN_80089dc8(param_2);
  return;
}
