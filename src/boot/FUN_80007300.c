/* FUN_80007300
 * image   boot (boot), base 0x80000480
 * address 0x80007300  body 0x80007300..0x8000731b  size 28 B
 * body sha256 bdbe9d3712c21746ed85dea4c9fee0abec77890ded6f995861c0888442a6730e
 * provider record sha256 0d6e5cc715f58c5b7136888d78adb7fee7904948ba3a8f7aa7c3bdb5527fb092
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80007300(uint param_1)

{
  setCopReg(0,Status,Status | param_1);
  return;
}
