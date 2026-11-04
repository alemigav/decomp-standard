/* func_8016e880
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016e880  body 0x8016e880..0x8016e8cf  size 80 B
 * body sha256 4cd6e5859850ecb07358658bf80b02c0f31dce20c461a4bc460592e1d69838af
 * provider record sha256 049626ae7055604926d31aa0ce963dc7a353883663b62be3aef79cb4238a2b9f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void processEntry entry(void)

{
  FUN_8016e8d0();
  do {
    (*(code *)(&PTR_FUN_80171860)[DAT_80171dd9])();
    FUN_8016fb54();
    func_0x8004cd88(1);
  } while( true );
}
