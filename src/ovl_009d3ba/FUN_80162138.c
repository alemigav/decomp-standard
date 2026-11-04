/* FUN_80162138
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162138  body 0x80162138..0x801621b3  size 124 B
 * body sha256 6fb56374a1ddaeea696bcc6533557fd72f463276f2929cabc62c666f6ec4c84a
 * provider record sha256 12c4a015b75f7a78ac50172d5e6fbfd802c1d7a9f955875a564bc808c7943687
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162138(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_80163098)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_801630b8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
