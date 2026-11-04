/* FUN_8016ab84
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016ab84  body 0x8016ab84..0x8016abe7  size 100 B
 * body sha256 e61ec33eb763e638fc1b2b0bc2ae6c43f85bb61793180b7bfcf95cae658e0c73
 * provider record sha256 9abf6b4cad883761a3c6da033d9e49b51e95ed11d69221b60aef7957f685a71a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016ab84(int param_1,undefined4 param_2)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 1) != 0) {
    (*(code *)(&PTR_LAB_8016c518)[*(byte *)(param_1 + 0x2c4)])();
    func_0x80066288(param_1,param_2);
  }
  return;
}
