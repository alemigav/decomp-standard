/* FUN_8004ce40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004ce40  body 0x8004ce40..0x8004ce8f  size 80 B
 * body sha256 843fc9c41661944944a6ae7b1030a2634ba1fa9f32cac8d94ce36dcefcbb544a
 * provider record sha256 f8f2db8128effbfa3ce2baa3b1304eacb17e27cb20878137372be6afc167688a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004ce40(undefined4 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_8010b6b8;
  if (DAT_8010b6b8 != (undefined2 *)0x0) {
    *(undefined4 *)(DAT_8010b6b8 + 0xdc) = param_1;
    *puVar1 = 2;
    func_0x80007450(0x80139b30,0,0);
    func_0x8000dcb0(0);
  }
  return;
}
