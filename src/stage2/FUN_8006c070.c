/* FUN_8006c070
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006c070  body 0x8006c070..0x8006c0d3  size 100 B
 * body sha256 34dce8b697de791aacb34fa3c107029251bddc3bf191dd6c78e3fc6996c8107e
 * provider record sha256 1f8876416eb0ece6f1688fcd742ea021030bb8dd97c919e3ff7e6009df8d6df2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006c070(int param_1)

{
  DAT_80112784 = param_1;
  if (param_1 == 0) {
    for (; DAT_80112788 != 0; DAT_80112788 = DAT_80112788 + -1) {
      osSendMesg(&DAT_80112a24,0,0);
    }
  }
  return;
}
