// @(#)default.lsl  1.16
//
//  Linker script file for the VX-toolset for C166
//

// Define the near page addresses. Each DPP will point to a near page.
// It is recommended to keep __DPP3_ADDR at 0x00C000
#define __DPP0_ADDR 0xC10000
#define __DPP1_ADDR 0xC20000
#define __DPP2_ADDR 0xE00000
#define __DPP3_ADDR 0x00C000

// Define the __MEMORY macro when you want to 
// define system memory yourself in this LSL file.
//#define __MEMORY

// Include the CPU specific .lsl file
// The CPU is specified by the __CPU__ macro
#ifndef __CPU__
#error No CPU defined, please link with -D__CPU__=<cpu>
#endif
#define __QUOTE_ME2(x) #x
#define __QUOTE_ME(x) __QUOTE_ME2(x)
#define CPULSL_FILE __QUOTE_ME(__CPU__.lsl)
#include CPULSL_FILE

#define APPL_AREA_START         0xC10080
#define APPL_AREA_END           0xCC0000

#define DSRAM_RESERVED_START    0x00A000
#define DSRAM_RESERVED_END      0x00A040

#define DPRAM_RESERVED_START    0x00F600
#define DPRAM_RESERVED_END      0x00F620

#define SYSTEM_STACK_AREA_START 0x00A040
#define SYSTEM_STACK_SIZE       0x1000
#define SYSTEM_STACK_AREA_END   SYSTEM_STACK_AREA_START + SYSTEM_STACK_SIZE

// Currently the user stack is located in the PSRAM
// because the canopen application needs ~10k and due
// to page restriction the linker can only locate a 8k
// stack into the 16k DSRAM (DSRAM goes from 0xA000 to 0xDFFF
// and therefore is not page aligned on the XC2267. Valid
// page addresses are 0x8000, 0xC000, ...)
section_layout ::near (direction = high_to_low)
{
    group ( run_addr = mem:spe:PSRAM ) stack "user_stack";
}

// Define the system stack
section_layout ::shuge (direction = high_to_low)
{
    group ( run_addr = [SYSTEM_STACK_AREA_START .. SYSTEM_STACK_AREA_END], ordered ) stack "system_stack" (size = SYSTEM_STACK_SIZE);
}

section_layout ::huge
{
    group my_huge_driver_ram ( run_addr = mem:spe:DSRAM )
    {
        select "io_driver_data_static" (attributes = +r+w);
        select "io_driver_data_global" (attributes = +r+w);
    }
    group my_application_dsram ( run_addr = mem:spe:DSRAM )
    {
            select "my_application_dsram";
    }
    
	group my_application_dpram ( run_addr = mem:spe:DPRAM )
    {
            select "my_application_dpram";
    }
    
    group my_huge_application_ram ( run_addr = mem:spe:PSRAM )
    {
        select "*" (attributes = +r+w);
    }

}


section_setup ::huge
{
	// 64 Bytes reserved for internal usage of the IO-Driver in the DSRAM
	// DO NOT MODIFY!
	reserved ( tag = "IO-Driver internal" ) DSRAM_RESERVED_START .. DSRAM_RESERVED_END;
	reserved ( tag = "DPRAM reserved" ) DPRAM_RESERVED_START .. DPRAM_RESERVED_END;
}

// Define interrupt vector table
// Resevere the whole first flash sector for the vector table.
section_setup ::code
{
    vector_table "vector_table" ( vector_size = 4, size = 116, run_addr = 0xC20000, 
                template="__vector_template", template_symbol="__lc_vector_target", 
                vector_prefix=".vector.", fill = loop)
    {
        vector (id=0, fill="__cstart");
    }
}


// reserve everything except the fist flash sector for the application
section_setup ::code
{
    reserved 0xC00000 .. 0xC0F000;
}

section_layout ::code
{
    group ( run_addr = [APPL_AREA_START .. APPL_AREA_END])
    {
        select "code_*";
    }

}


#define __DTC_START
// using on-chip memory only

#define __DTC_END




#define __FLASH_START
/*******************************************************************************
 * TASKING Linker Script part for flash devices
 * Automatically-generated. Do not edit!
 ******************************************************************************/
#define __FLASH_END


