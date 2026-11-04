/* FUN_80165ff0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165ff0  body 0x80165ff0..0x8016601b  size 44 B
 * body sha256 cc4cd916a8222580c93e5123588002bb62e09c274c8297a02be121eb2b354ed7
 * provider record sha256 8cfab1247b7eadaa271257544690c0a54a6672d1421ec2fab5d332b50043a829
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165ff0(int param_1)

{
  if (*(uint *)(param_1 + 0x28c) < 0x708) {
    FUN_80165c68(param_1,7);
  }
  return;
}
