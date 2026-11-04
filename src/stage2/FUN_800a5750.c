/* FUN_800a5750
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5750  body 0x800a5750..0x800a5793  size 68 B
 * body sha256 07592e8792b643b8500a56c9b19b0911b590b305ac530f647035591b062861fe
 * provider record sha256 3c0af7337b65fb66ac5ee51c25d484872ac13eb6fcef458fade19e1e5da65edb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a5750(void)

{
  if (DAT_80143f4d != '\0') {
    (*_DAT_80143ff4)();
    func_0x80011390();
    DAT_80143f4d = '\0';
  }
  return;
}
