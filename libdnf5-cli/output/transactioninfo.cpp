/*
Copyright Contributors to the libdnf project.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "libdnf5-cli/output/transactioninfo.hpp"

#include "utils/string.hpp"


namespace libdnf5::cli::output {

void print_transaction_info(libdnf5::transaction::Transaction & transaction) {
    KeyValueTable info;
    info.add_line("Transaction ID", transaction.get_id(), "bold");
    info.add_line("Begin time", libdnf5::utils::string::format_epoch(transaction.get_dt_start()));
    info.add_line("Begin rpmdb", transaction.get_rpmdb_version_begin());
    info.add_line("End time", libdnf5::utils::string::format_epoch(transaction.get_dt_end()));
    info.add_line("End rpmdb", transaction.get_rpmdb_version_end());

    if (transaction.get_username() != NULL) {
        info.add_line("User", transaction.get_username())
    } else {
        info.add_line("User", transaction.get_user_id());
    }

    info.add_line("Status", libdnf5::transaction::transaction_state_to_string(transaction.get_state()));
    info.add_line("Releasever", transaction.get_releasever());
    info.add_line("Description", transaction.get_description());
    info.add_line("Comment", transaction.get_comment());

    info.print();
    print_transaction_item_table(transaction.get_packages(), "Packages altered:");
    print_transaction_item_table(transaction.get_comps_groups(), "Groups altered:");
    print_transaction_item_table(transaction.get_comps_environments(), "Environments altered:");
}

}  // namespace libdnf5::cli::output
