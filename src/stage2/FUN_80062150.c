/* FUN_80062150
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80062150  body 0x80062150..0x80062183  size 52 B
 * body sha256 2bcc7ccf9e3cc9b4a9abcd63c29a50a5e274463cf6e5e83651a199f24fdf059b
 * provider record sha256 e90cd2fac3f80814dce82159636c0967e0f91a126284c9d0a2fd85249a073696
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80062150(int param_1)

{
  (*(code *)(&PTR_FUN_80111130)[*(byte *)(param_1 + 6)])();
  return;
}
